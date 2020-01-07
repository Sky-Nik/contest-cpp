int string_distance_l(string s, string t) {
    if (s.length() != t.length()) {
        return numeric_limits<int>::max();
    }
    int answer = 0;
    for (int i = 0; i < s.length(); ++i) {
        answer += abs(s[i] - t[i]);
    }
    return answer;
}

int string_distance_c(string s, string t) {
    if (s.length() != t.length()) {
        return numeric_limits<int>::max();
    }
    int answer = 0;
    for (int i = 0; i < s.length(); ++i) {
        int chars_distance = abs(s[i] - t[i]);
        answer += min(chars_distance, 26 - chars_distance);
    }
    return answer;   
}
