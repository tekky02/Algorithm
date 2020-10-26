/**
 * @ Author: tekky
 * @ Create Time: 2020-10-26 12:30:50
 * @ Modified by: tekky
 * @ Modified time: 2020-10-26 12:31:01
 */

type MapSum struct {
	item map[string]int
}

/** Initialize your data structure here. */
func Constructor() MapSum {
	return MapSum{
		item: make(map[string]int),
	}
}

func (this *MapSum) Insert(key string, val int) {
	this.item[key] = val
}

func (this *MapSum) Sum(prefix string) (ans int) {
	for k, v := range this.item {
		if strings.HasPrefix(k, prefix) {
			ans += v
		}
	}
	return
}

/**
 * Your MapSum object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(key,val);
 * param_2 := obj.Sum(prefix);
 */
