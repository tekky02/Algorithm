/*
 * @Author: tekky
 * @Date: 2020-12-05 20:11:51
 * @Last Modified by:   tekky
 * @Last Modified time: 2020-12-05 20:11:51
 */
import "container/list"

type Node struct {
	value int
	iter  *list.Element
}

type LRUCache struct {
	capacity int
	keys     *list.List
	items    map[int]*Node
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		capacity: capacity,
		keys:     list.New(),
		items:    make(map[int]*Node),
	}
}

func (this *LRUCache) Get(key int) int {
	if v, ok := this.items[key]; ok {
		this.keys.Remove(v.iter)
		this.keys.PushFront(key)
		this.items[key].iter = this.keys.Front()
		return v.value
	}
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	if v, ok := this.items[key]; ok {
		this.keys.Remove(v.iter)
		this.keys.PushFront(key)
		this.items[key] = &Node{value, this.keys.Front()}
		return
	}
	if len(this.items) == this.capacity {
		delete(this.items, this.keys.Back().Value.(int))
		this.keys.Remove(this.keys.Back())
	}
	this.keys.PushFront(key)
	this.items[key] = &Node{value, this.keys.Front()}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */