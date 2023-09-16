/**
 * @return {number}
 */
var argumentsLength = function (...args) {
    let ret = 0;
    args.forEach(el => ++ret)
    return ret;
};

// console.log(argumentsLength(3, 4, {}, null));

/**
 * argumentsLength(1, 2, 3); // 3
 */
