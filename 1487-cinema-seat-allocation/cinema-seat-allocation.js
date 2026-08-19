/**
 * @param {number} n
 * @param {number[][]} rs
 * @return {number}
 */
var maxNumberOfFamilies = function(n, rs) {
    let total = n;
    
    const N = rs.length;
    rs.sort();

    let l = 0;
    let result = 0;
    let g1 = !(rs[l][1] >= 2 && rs[l][1] <= 5),
        g2 = !(rs[l][1] >= 4 && rs[l][1] <= 7),
        g3 = !(rs[l][1] >= 6 && rs[l][1] <= 9);
    for (let r = 1; r < N; r++) {
        if (rs[r][0] == rs[l][0]) {
            g1 &&= !(rs[r][1] >= 2 && rs[r][1] <= 5);
            g2 &&= !(rs[r][1] >= 4 && rs[r][1] <= 7);
            g3 &&= !(rs[r][1] >= 6 && rs[r][1] <= 9);
        } else {
            if (g1 && g3) {
                result += 2;
            } else if (g1 || g2 || g3) {
                result++;
            }

            total--;
            l = r;
            g1 = !(rs[l][1] >= 2 && rs[l][1] <= 5);
            g2 = !(rs[l][1] >= 4 && rs[l][1] <= 7);
            g3 = !(rs[l][1] >= 6 && rs[l][1] <= 9);
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