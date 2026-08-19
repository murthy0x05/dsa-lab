/**
 * @param {number} n
 * @param {number[][]} reservedSeats
 * @return {number}
 */
var maxNumberOfFamilies = function(n, reservedSeats) {
    let total = n;
    
    const N = reservedSeats.length;
    reservedSeats.sort();

    let l = 0;
    let result = 0;
    let g1 = !(reservedSeats[l][1] >= 2 && reservedSeats[l][1] <= 5),
        g2 = !(reservedSeats[l][1] >= 4 && reservedSeats[l][1] <= 7),
        g3 = !(reservedSeats[l][1] >= 6 && reservedSeats[l][1] <= 9);
    for (let r = 1; r < N; r++) {
        if (reservedSeats[r][0] == reservedSeats[l][0]) {
            let seat = reservedSeats[r][1];
            g1 &&= !(seat >= 2 && seat <= 5);
            g2 &&= !(seat >= 4 && seat <= 7);
            g3 &&= !(seat >= 6 && seat <= 9);
        } else {
            if (g1 && g3) {
                result += 2;
            } else if (g1 || g2 || g3) {
                result++;
            }

            total--;
            l = r;
            g1 = !(reservedSeats[l][1] >= 2 && reservedSeats[l][1] <= 5);
            g2 = !(reservedSeats[l][1] >= 4 && reservedSeats[l][1] <= 7);
            g3 = !(reservedSeats[l][1] >= 6 && reservedSeats[l][1] <= 9);
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