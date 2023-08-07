const isPalindrome = function (str) {
    if (str === " "  ) return true;
    str = str.toLowerCase().replace(/[^A-Za-z0-9]/g, '');
    
    // if (str === "")
        // return false;
    
    let reversed = str.split('').reverse().join('');
    return str === reversed;
};
