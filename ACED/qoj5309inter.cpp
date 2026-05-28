#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cassert>
using namespace std;

int main(int argc, char* argv[]) {
    long long n = 1000;
    int start = 1;

    const int MAX_QUERIES = 10000;
    int queries = 0;
    long long current = start;
    string cmd;

    while (true) {
        if (!(cin >> cmd)) {
            cerr << "WA: unexpected end of solution output" << endl;
            return 1;
        }

        if (cmd == "walk") {
            long long x;
            if (!(cin >> x)) {
                cerr << "WA: invalid walk format" << endl;
                return 1;
            }
            if (x < 0 || x > 1000000000) {
                cerr << "WA: x out of range" << endl;
                return 1;
            }

            queries++;
            if (queries > MAX_QUERIES) {
                cerr << "WA: too many queries" << endl;
                return 1;
            }

            // 在环上移动：1-indexed，当前在 current，走 x 步
            current = (current - 1 + x) % n + 1;
            cout << current << endl;   // endl 自动 flush
        }
        else if (cmd == "guess") {
            long long guess_n;
            if (!(cin >> guess_n)) {
                cerr << "WA: invalid guess format" << endl;
                return 1;
            }

            if (guess_n == n) {
                cerr << "OK: n = " << n << endl;
                return 0;   // AC
            } else {
                cerr << "WA: guessed " << guess_n << ", but n = " << n << endl;
                return 1;
            }
        }
        else {
            cerr << "WA: unknown command '" << cmd << "'" << endl;
            return 1;
        }
    }
}