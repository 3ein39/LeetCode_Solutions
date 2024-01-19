

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    let seen = [];
    while (head) {
        if (seen.find((el) => {
            return el === head;
        }) !== undefined)
            return true;

        seen.push(head)
        head = head.next;
    }

    return false;
};
