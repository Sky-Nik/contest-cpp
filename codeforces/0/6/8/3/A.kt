fun main() {
    var (a, x, y) = readLine()!!.split(' ').map(String::toLong)
    var k1: Long = x * (a - x)
    var k2: Long = y * (a - y)
    if (k1 < 0L || k2 < 0L) {
        println("2")
    } else if (k1 == 0L || k2 == 0L) {
        println("1")
    } else {
        println("0")
    }
}
