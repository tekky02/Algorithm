/**
 * @ Author: tekky
 * @ Create Time: 2020-11-02 21:34:34
 * @ Last Modified by: tekky
 * @ Last Modified time: 2020-11-02 21:34:44
 */

const (
	Big = iota + 1
	Medium
	Small
)

type ParkingSystem struct {
	slots map[int]int
}

func Constructor(big int, medium int, small int) ParkingSystem {
	slots := make(map[int]int)
	slots[Big] = big
	slots[Medium] = medium
	slots[Small] = small
	return ParkingSystem{
		slots: slots,
	}
}

func (this *ParkingSystem) AddCar(carType int) bool {
	if this.slots[carType] > 0 {
		this.slots[carType]--
		return true
	}
	return false
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * obj := Constructor(big, medium, small);
 * param_1 := obj.AddCar(carType);
 */