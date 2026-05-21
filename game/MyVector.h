#pragma once
#include<iostream>
#include<algorithm>

struct Item;
bool compareByPrice(const Item& a, const Item& b);

template <typename T>
class MyVector {
private:
	T* pItems_;
	int capacity_;
	int size_;
public:
	MyVector() {
		capacity_ = 10;
		size_ = 0;
		pItems_ = new T[capacity_];
	}
	~MyVector() {
		if (pItems_ != nullptr) {
			delete[] pItems_;
			pItems_ = nullptr;
		}
	}
	MyVector(const MyVector& other) {
		capacity_ = other.capacity_;
		size_ = other.size_;

		pItems_ = new T[capacity_];

		for (int i = 0; i < size_; i++) {
			pItems_[i] = other.pItems_[i];
		}
	}
	int GetSize() const { return size_; }
	int GetCapacity() const { return capacity_; }

	void AddItem(const T& item) {
		if (size_ >= capacity_) {
			std::cout << "아이템 추가 시도... (현재 "<< size_ << "/" << capacity_ << std::endl;
			Resize(capacity_ * 2);
			std::cout << "-> 인벤토리 자동 확장! (" << capacity_ / 2 << " -> " << capacity_ << ")" << std::endl;
		}
		pItems_[size_] = item;
		size_++;
	}

	void RemoveLastItem() {
		if (size_ == 0) {
			std::cout << "아이템이 없습니다" << std::endl;
			return;
		}
		size_--;
	}

	void Resize(int newCapacity) {
		T* pNewItems = new T[newCapacity];

		for (int i = 0; i < size_; i++) {
			pNewItems[i] = pItems_[i];
		}

		if (pItems_ != nullptr) {
			delete[] pItems_;
		}

		pItems_ = pNewItems;
		capacity_ = newCapacity;
	}

	void PrintAllItems() const {
		std::cout << "\n[ 인벤토리 (" << size_ << "/" << capacity_ << ") ]" << std::endl;

		if (size_ == 0) {
			std::cout << "아이템이 없습니다" << std::endl;
			std::cout << std::endl;
			return; 
		}

		for (int i = 0; i < size_; i++) {
			std::cout << i + 1 << ". " << pItems_[i].name << " (" << pItems_[i].price << "G)" << std::endl;
		}
		std::cout << std::endl;
	}

	void SortItems() {
		std::sort(pItems_, pItems_ + size_, compareByPrice);
	}

	T& GetItem(int index) { return pItems_[index]; }

	void Erase(int index) {
		if (index < 0 || index >= size_) {
			std::cout << "❌ 잘못된 인덱스입니다." << std::endl;
			return;
		}

		for (int i = index; i < size_ - 1; i++) {
			pItems_[i] = pItems_[i + 1];
		}
		size_--;
	}
};

