/**
 * @param {number} n
 * @param {number[][]} reservedSeats
 * @return {number}
 */
var maxNumberOfFamilies = function(n, reservedSeats) {
    let total = n;
    
    const N = reservedSeats.length;
    reservedSeats.sort();

    const gs1 = new Set([2, 3, 4, 5]);
    const gs2 = new Set([4, 5, 6, 7]);
    const gs3 = new Set([6, 7, 8, 9]);
    let l = 0;
    let result = 0;
    let g1 = !gs1.has(reservedSeats[l][1]),
        g2 = !gs2.has(reservedSeats[l][1]),
        g3 = !gs3.has(reservedSeats[l][1]);
    for (let r = 1; r < N; r++) {
        if (reservedSeats[r][0] == reservedSeats[l][0]) {
            g1 &&= !gs1.has(reservedSeats[r][1]);
            g2 &&= !gs2.has(reservedSeats[r][1]);
            g3 &&= !gs3.has(reservedSeats[r][1]);
        } else {
            if (g1 && g3) {
                result += 2;
            } else if (g1 || g2 || g3) {
                result++;
            }

            total--;
            l = r;
            g1 = !gs1.has(reservedSeats[l][1]);
            g2 = !gs2.has(reservedSeats[l][1]);
            g3 = !gs3.has(reservedSeats[l][1]);
        }
    }
    
    if (g1 && g3) {
        result += 2;
    } else if (g1 || g2 || g3) {
        result++;
    }
    total--;

    result += total * 2;

    return result;
};