#include<iostream>
#include<string>
#include<list>
#define listout(x) for(auto s : x) cout << " " << s; cout << endl;
using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;
	
	list<int> deck;
	for (int i = 1; i < N + 1; i++)
		deck.push_back(i);

	for (int i = 0; i < K; i++) {
		string process; cin >> process;
		if (process == "Shuffle") {
			auto itS = deck.begin();
			auto itM = next(itS++, N / 2);
			auto itE = next(itM, 1);
			while (itE != deck.end()) {
				deck.splice(itS++, deck, itM);
				itM = itE++;
			}
		}
		else if (process == "Cut") {
			int s, e; cin >> s >> e;
			auto itS = deck.begin(); advance(itS, --s);
			auto itE = deck.begin(); advance(itE, e);

			deck.splice(deck.end(), deck, itS, itE);
		}
	}
	auto it = deck.begin();
	cout << *it << " ";
	advance(it, N / 2 - 1);
	cout << *it << " ";
	advance(it, N / 2);
	cout << *it;

	return 0;
}