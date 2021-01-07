/* Is Prime */

package main

import (
	"fmt"
	"math"
)

func isPrime(number int) string {
	// is the number prime

	// I'm not sure this is nessary, but ' and " and different
	error1 := "The number cannot be below or equal to 1"
	prime := "prime"
	noPrime := "not " + prime

	// if 1, 0, or negative return an error
	if number <= 1 {
		return error1
	} else {
		// if less than prime, it is prime, otherwise,
		// check if it is even, ends in 5 or divisible by 3 it is not prime
		if number <= 5 && number != 4 {
			return prime
		} else if number%10%2 == 0 || number%10 == 5 {
			return noPrime
		} else if number%3 == 0 {
			return noPrime
		} else {

			base := float64(number)
			var highestCheck float64 = math.Pow(base, 0.5)
			// for i starting at 7 and incrementing a 2
			for i := 7; float64(i) >= highestCheck; i += 2 {
				// if multiple of 3, continue otherwise
				// if it is module the index, it is not prime
				if i%3 == 0 {
					continue
				} else if number%i == 0 {
					return noPrime
				}
			}

			// if not flag, it is prime
			return prime
		}
	}
}

func main() {
	// chose any number
	number := 146192364271

	fmt.Println(isPrime(number))
}
