#include <iostream>
#include <vector>
using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {

    vector<vector<int>> arr(n);
    vector<int> answer;

    int lastAnswer = 0;

    for (auto query : queries) {

        int type = query[0];
        int x = query[1];
        int y = query[2];

        int index = (x ^ lastAnswer) % n;

        if (type == 1) {
            arr[index].push_back(y);
        }
        else if (type == 2) {
            lastAnswer = arr[index][y % arr[index].size()];
            answer.push_back(lastAnswer);
        }
    }

    return answer;
}

int main() {

    int n, q;
    cin >> n >> q;

    vector<vector<int>> queries(q, vector<int>(3));

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0]
            >> queries[i][1]
            >> queries[i][2];
    }

    vector<int> result = dynamicArray(n, queries);

    for (int x : result) {
        cout << x << endl;
    }

    return 0;
}