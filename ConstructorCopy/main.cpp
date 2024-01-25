#include<iostream>

class Integer {
public:
	Integer() :data_(0) {}
	Integer(int num) :data_(num) {}

	// перегрузка оператора как дружественной функции
	friend Integer operator +(Integer A, Integer B) {
		Integer result;
		result.data_ = A.data_ + B.data_;
		return result;
	}

	friend std::ostream& operator <<(std::ostream& out, const Integer& obj) { // friend для возможности работы с приватными полями
		return out << obj.data_;
	}
	int GetNum() {
		return data_;
	}

	// оператор перегружен как метод класса
	Integer& operator=(const Integer& other) {
		this->data_ = other.data_;
		return *this;
	}

private:
	int data_;	
	// Реализация математически достоверного целого числа
	/*bool sign_;
	unsigned long long units_;*/
};

// перегрузка оператора как независимой функции
Integer operator-(Integer a, Integer b) {
	return a.GetNum() - b.GetNum();
}

Integer operator*(Integer a, Integer b) {
	return a.GetNum() * b.GetNum();
}

int main() {
	setlocale(LC_ALL, "Russian");
	Integer a{ 5 };
	Integer b{ 8 };
	
	

	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * b << std::endl;
	//-----------------------------
	std::cout << a + 5 << std::endl;
	std::cout << a - 5 << std::endl;
	std::cout << a * 5 << std::endl;
	//-----------------------------
	std::cout << 4 + b << std::endl;
	std::cout << 7 - b << std::endl;
	std::cout << 1 * b << std::endl;
	
	return 0;
}
