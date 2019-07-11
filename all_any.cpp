template<typename T>
bool all(vector<T>& v) {
    for (const T& e: v) {
        if (!e) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool any(vector<T>& v) {
    for (const T& e: v) {
        if (e) {
            return true;
        }
    }
    return false;
}