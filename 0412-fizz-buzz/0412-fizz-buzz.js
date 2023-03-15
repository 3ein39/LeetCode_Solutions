/**
 * @param {number} n
 * @return {string}
 */
var fizzBuzz = function(n) {
    let answer = [];
    for (let i = 1; i <= n; ++i) {
        if (i % 3 === 0 && i % 5 === 0)
            answer =  answer.concat("FizzBuzz");
        else if (i % 3 === 0)
            answer = answer.concat("Fizz");
        else if (i % 5 === 0)
            answer = answer.concat("Buzz");
        else
            answer = answer.concat(i.toString());
    }
    return answer;
};

// console.dir(fizzBuzz(3));
