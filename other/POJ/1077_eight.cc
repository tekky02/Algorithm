// 1077_eight.cc
// created by tekky on 2020.11.17.


class EightPuzzle {
public:
	enum { SIZE = 9 }
	explicit EightPuzzle(std::string const& puzzle_);
	~EightPuzzle();
	void print();
	void init();

private:
	bool canMoveUp(int pos)    const { return pos > 2; }
	bool canMoveDown(int pos)  const { return pos < 6; }
	bool canMoveLeft(int pos)  const { return pos % 3 != 0; }
	bool canMoveRight(int pos) const { return pos % 3 != 2; }

	int getPos() const;
	bool isSolvable(char target[]) const;
	bool run();

	void operation();
	void move(int mov);

private:
	std::string puzzle;
	std::string target;
	unsigned f; // f(n) = g(n) + h(n).
	unsigned g; // g(n) -- deepth.
	unsigned h; // h(n) -- 所有位置错误的点到目标点的曼哈顿距离之和.
	std::string ans;
};

EightPuzzle::EightPuzzle(std::string const& puzzle_) :
	puzzle(puzzle_),
	target("12345678x"),
	f(0),
	g(0),
	h(0)
{
}


int EightPuzzle::getPos() const {
	for (int i = 0; i < SIZE; ++i) 
		if (puzzle[i] == 'x')
			return i;
	return -1;
}

bool EightPuzzle::isSolvable(char target[]) {
	int reverse = 0;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < i; ++j) {
			if (puzzle[j] > puzzle[i] && (puzzle[j] != 'x' && puzzle[i] != 'x'))
				++reverse;
			if (target[j] > target[i] && (target[j] != 'x' && target[i] != 'x'))
				++reverse;
		}
	}
	return reverse % 2 == 0;
}

bool EightPuzzle::run() {
	if (!isSolvable()) {
		return false;
	}
	// TODO:
	while (true) {
		if (canMoveUp()) {

		}
		if (canMoveDown()) {

		}
		if (canMoveLeft()) {

		}
		if (canMoveRight()) {
			
		}
	}
}

void EightPuzzle::print() {
	bool res = run();
	std::cout << (res ? ans : "unsolvable") << std::endl;
}

int main(int argc, char const *argv[])
{
	std::string s;
	char c;
	for (int i = 0; i < 9; ++i) {
		std::cin >> c;
		s += c;
	}

	EightPuzzle puzzle(s);

	// puzzle.run();
	puzzle.print();
	return 0;
}