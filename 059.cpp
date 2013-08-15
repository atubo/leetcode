#include <utility>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class SpiralStepper {
public:
    SpiralStepper(int n): m_counter1(n), m_counter2(1), m_counter3(n),
                          m_dir(0), m_x(-1), m_y(0) {}

    bool hasMore() const {
        return !(m_counter3 == 0 && m_counter2 == 1 && m_counter1 == 1);
    }

    pair<int, int> goNext() {
        assert(hasMore());
        if (m_counter3 == 0) {
            if (--m_counter2 == 0) {
                m_counter2 = 2;
                m_counter1--;
            }
            m_counter3 = m_counter1;
            m_dir = (m_dir + 1) % 4;
        }
        switch (m_dir) {
            case 0:
                m_x++;
                break;
            case 1:
                m_y++;
                break;
            case 2:
                m_x--;
                break;
            case 3:
                m_y--;
                break;
            default:
                assert(0);
                break;
        }
        m_counter3--;
        return make_pair(m_x, m_y);
    }
private:
    int m_counter1; // maximum number of steps this segment
    int m_counter2; // count down to decrease m_counter1
    int m_counter3; // remaining number of steps
    int m_dir;
    int m_x;
    int m_y;
};

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n, 0));
        SpiralStepper stepper(n);
        for (int i = 0; i < n * n; i++) {
            assert(stepper.hasMore());
            pair<int, int> pos = stepper.goNext();
            result[pos.second][pos.first] = i + 1;
        }
        return result;
    }
};

#if 0
int main()
{
    int n;
    cin >> n;
    Solution s;
    vector<vector<int> > matrix = s.generateMatrix(n);
    for (int i = 0; i < (int)matrix.size(); i++) {
        for (int j = 0; j < (int)matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#endif

