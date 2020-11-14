/**
 * @ Author: tekky
 * @ Create Time: 2020-11-14 13:49:02
 * @ Last Modified by: tekky
 * @ Last Modified time: 2020-11-14 16:47:19
 */

// 1042_gone_fishing.cc
// created by tekky on 2020.11.15.

#include <cstdio>
#include <cstring>

const int unit = 5; // five-minutes unit.
int fi[26];
int di[26];
int ti[25];
int tempfi[26];
int tempti[26]; // time spend on each lake.
int n, h;

struct {
    int time[26]; // time spend on each lake.
    int fish;
} ans;

int maxfish(int lake[], int size) {
    int max = lake[1];
    int idx = 1;
    
    for (int i = 2; i <= size; ++i) {
        if (max < lake[i]) max = lake[i], idx = i;
    }
    return idx;
}

void solution() {

    ans.fish = -1;
    for (int i = 1; i <= n; ++i) { 
        // assume stop fishing at lake i.
        std::memcpy(tempfi, fi, sizeof(tempfi));
        std::memset(tempti, 0, sizeof(tempti));
        
        int time = h * 60;
        
        // substract the time spend on moving...
        for (int j = 1; j < i; ++j) time -= ti[j] * 5;

        int fish = 0;
        while (time > 0) {
            int idx = maxfish(tempfi, i);
            fish += tempfi[idx];
            tempfi[idx] = tempfi[idx] > di[idx] ? tempfi[idx] - di[idx] : 0;
            tempti[idx] += 5;
            time -= 5;
        }
        if (fish > ans.fish) {
            std::memcpy(ans.time, tempti, sizeof(tempti));
            ans.fish = fish;
        }
    }
}

void print(int n) {
    for (int i = 1; i <= n; ++i) {
        if (i != n) std::printf("%d, ", ans.time[i]);
        else        std::printf("%d\n", ans.time[i]);
    }
    std::printf("Number of fish expected: %d\n\n", ans.fish);
}

int main(int argc, char const *argv[])
{
    fi[0] = ti[0] = di[0] = 0;

    while (std::scanf("%d", &n), n) {
        
        std::memset(&ans, 0, sizeof(ans));

        std::scanf("%d", &h);

        for (int i = 1; i <= n; ++i) std::scanf("%d", &fi[i]);
        for (int i = 1; i <= n; ++i) std::scanf("%d", &di[i]);
        for (int i = 1; i < n; ++i)  std::scanf("%d", &ti[i]);

        solution();

        print(n);
    }
    return 0;
}
