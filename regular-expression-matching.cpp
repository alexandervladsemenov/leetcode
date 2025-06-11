#include "common.h"

std::vector<std::vector<std::optional<bool> > > dp;

bool compare(char a, char b) {
    if ((a == '.' || b == '.') && a != '\0' && b != '\0') return true;
    if (a == b) return true;
    return false;
}

bool isMatch(char *s, char *p, size_t s_start, size_t p_start) {
    int s_count = 0;
    int p_count = 0;
    bool answer = false;
    while (s[s_count] != '\0' && p[p_count] != '\0') {
        char s_char = s[s_count];
        char p_char = p[p_count];
        char p_next_char = p[p_count + 1];
        if (p_next_char == '*') {
            if (dp[s_start + s_count][p_start + p_count + 2].has_value())
                answer |= dp[s_start + s_count][p_start + p_count + 2].value();
            else
                answer |= isMatch(s + s_count, p + p_count + 2, s_count, p_count + 2);
            while (s[s_count] != '\0') {
                if (compare(s[s_count], p_char)) {
                    s_count++;
                    if (dp[s_start + s_count][p_start + p_count + 2].has_value())
                        answer |= dp[s_start + s_count][p_start + p_count + 2].value();
                    else
                        answer |= isMatch(s + s_count, p + p_count + 2, s_count, p_count + 2);
                } else {
                    break;
                }
            }
            return answer;;
        } else {
            bool flag = compare(s_char, p_char);
            if (!flag) {
                dp[s_start][p_start] = false;
                return false;
            }
            s_count++;
            p_count++;
        }
    }
    if (s[s_count] != '\0') {
        dp[s_start][p_start] = false;
        return false;
    }
    if (p[p_count] != '\0') {
        char p_next_char = p[p_count + 1];
        if (p_next_char == '*') {
            if (dp[s_start + s_count][p_start + p_count + 2].has_value())
                answer |= dp[s_start + s_count][p_start + p_count + 2].value();
            else
                answer |= isMatch(s + s_count, p + p_count + 2, s_count, p_count + 2);
        } else {
            dp[s_start][p_start] = false;
            return false;
        };
    }
    dp[s_start][p_start] = answer | compare(s[s_count], p[p_count]);
    return answer | compare(s[s_count], p[p_count]);
}

bool isMatch(string s, string p) {
    dp.resize(s.size() + 1);
    for (auto &el: dp) {
        el.resize(p.size() + 1);
    }

    return isMatch(s.data(), p.data(), 0, 0);
}

int main() {
    std::string s = "b", p = "b.*c*";
    std::cout << isMatch(s, p);
    return 0;
}
