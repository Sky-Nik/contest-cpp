template<typename T>
T min_(T t) {
    return t;
}

template<typename T, typename... Args>
T min_(T t, Args... args) {
    return min(t, min_(args...));
}

template<typename T>
T max_(T t) {
    return t;
}

template<typename T, typename... Args>
T max_(T t, Args... args) {
    return max(t, max_(args...));
}
