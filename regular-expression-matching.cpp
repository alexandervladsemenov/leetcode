#include "common.h"

std::vector<std::vector<std::optional<bool>>> dp;

bool compare(char a, char b) {
    if (a == '.' || b == '.') return true;
    if (a == b) return true;
    return false;
}

bool isMatch(char *s, char *p, size_t s_start, size_t p_start) {
    size_t p_count = 0;
    size_t s_count = 0;

    while (s[s_count] != '\0' && p[p_count] != '\0' && p[p_count] != '*') {
        if (!compare(p[p_count], s[s_count])) {
            dp[s_start][p_start] = false;
            return false;
        };
        p_count++;
        s_count++;
    }
    if (p[p_count] == '*') {
        char prev_p = p[p_count - 1];
        if (p[p_count + 1] == '\0') {
            while (s[s_count] != '\0') {
                if (!compare(prev_p, s[s_count])) {
                    dp[s_start][p_start] = false;
                    return false;
                }
                s_count++;
            }
            dp[s_start][p_start] = true;
            return true;
        } else {
            bool answer = false;
            while (s[s_count] != '\0') {
                if (compare(prev_p, s[s_count])) {
                    if (!dp[s_count][p_count + 1].has_value())
                        answer |= isMatch(s + s_count, p + p_count + 1, s_count,
                                          p_count + 1);
                    else
                        answer |= dp[s_count][p_count + 1].value();
                    s_count++;
                } else {
                    break;
                }
            }
            dp[s_start][p_start] = answer;
            return answer;
        }

    } else {
        dp[s_start][p_start] = compare(p[p_count], s[s_count]);
        return compare(p[p_count], s[s_count]);
    }
}

bool isMatch(string s, string p) {
    dp.resize(s.size());
    for (auto &el : dp) {
        el.resize(s.size());
    }

    return isMatch(s.data(), p.data(),0,0);
}

int main() {
    std::string s = "abddadas", p = "abd.*das*";
    std::cout << isMatch(s, p);
    return 0;
}