/* Binary search to find 
 * the smallest value of x 
 * with checker(x) true.
 * Typename T should model
 * totally ordered discrete set. */
template <typename T>
T binary_search_z(T lower_bound, T upper_bound, bool(*checker) (T)) {
    T middle;
    while (lower_bound < upper_bound) {
        middle = (lower_bound + upper_bound) >> 1;
        if ((*checker)(middle)) {
            upper_bound = middle;
        } else {
            lower_bound = middle + 1;
        }
    }
    return lower_bound;
}

/* Binary search to find 
 * the smallest value of x 
 * with checker(x) true.
 * Typename T should model
 * totally ordered continuous set. */
template <typename T>
T binary_search_r(T lower_bound, T upper_bound, bool(*checker) (T), T precision) {
    T middle;
    while (lower_bound + precision < upper_bound) {
        middle = (lower_bound + upper_bound) / 2.;
        if ((*checker)(middle)) {
            upper_bound = middle;
        } else {
            lower_bound = middle;
        }
    }
    return (lower_bound + upper_bound) / 2;
}
