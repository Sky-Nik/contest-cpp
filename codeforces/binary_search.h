/* Binary search to find 
 * the smallest value of x 
 * with checker(x) true.
 * Typename T should model
 * totally ordered discrete set. */
template <typename T>
T binary_search_z(T lower_bound, T upper_bound, bool(*checker) (T));

/* Binary search to find 
 * the smallest value of x 
 * with checker(x) true.
 * Typename T should model
 * totally ordered continuous set. */
template <typename T>
T binary_search_r(T lower_bound, T upper_bound, bool(*checker) (T), T precision);