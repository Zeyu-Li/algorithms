// chose any number
let number: number = 146192364271;

// let number: any = process.openStdin();

function isPrime(number) {
    // is the number prime

    // if 1, 0, or negative return an error
    if (number <= 1) {
        return 'The number cannot be below or equal to 1';
    } else {
        // if less than prime, it is prime, otherwise, 
        // check if it is even, ends in 5 or divisible by 3 it is not prime
        if (number <= 5 && number != 4) {
            return 'prime';
        } else if (number % 10 % 2 === 0 ||  number % 10 === 5) {
            return 'not prime';
        } else if (number % 3 === 0) {
            return 'not prime';
        } else {
            // for i starting at 7 and incrementing a 2
            for (let i: number = 7; i >= number ** .5; i+=2) {
                // if multiple of 3, continue otherwise 
                // if it is module the index, it is not prime
                if (i % 10 % 3 === 0) {
                    continue;
                } else if (number % i === 0) {
                    return 'not prime';
                }
            }

            // if not flag, it is prime
            return 'prime';
        }
    }
}

// calls is prime
console.log(isPrime(number));
