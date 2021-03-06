#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 1;
const int MAX_N = 8;

const int rnd_test_n = 100;
const int extreme_test_n = 10;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
	dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(string& s) {
	ostringstream oss;
    oss << s << endl;
	return oss.str();
}

string generate_hex_string(int n){
    pattern p("[0-9a-f]{"+to_string(n)+","+to_string(n)+"}");
    return p.next(rnd);
}

vector<string> generate_sample_tests() {
	vector<string> tests;
    string s = "0";
    tests.push_back(output_tc(s));
    s = "f39";
    tests.push_back(output_tc(s));
    s = "abc";
    tests.push_back(output_tc(s));
	return tests;
}



string rnd_test(int i){
    int min_n = MIN_N;
    int max_n = MAX_N;
    
    if(i<rnd_test_n/3){
        max_n = 3;
    }
    else if(i<rnd_test_n/2){
        max_n = 5;
    }

    int n = rnd.next(min_n,max_n);
    string s = generate_hex_string(n);
    return output_tc(s);
}

vector<string> generate_random_tests() { 
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++){
        tests.push_back(rnd_test(i));
    } 
    return tests;
}


string extreme_test(){
    string s = generate_hex_string(MAX_N);
    return output_tc(s);
}

vector<string> generate_extreme_tests(){
    vector<string> tests;
    tests.push_back("ffffffff\n");
    tests.push_back("00000000\n");
    for(int i=0;i<extreme_test_n;i++){
        tests.push_back(extreme_test());
    }   
    return tests;
}

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	vector<string> tests;
	size_t test = 0;
	append(tests, generate_sample_tests());
	append(tests, generate_random_tests());
	append(tests, generate_extreme_tests());
	for (const auto &t : tests) {
		startTest(++test);
		cout << t;
	}
	return 0;
}