class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        N = len(asteroids)

        S = []
        for asteroid in asteroids:
            if S:
                if S[-1] < 0:
                    S.append(asteroid)
                elif S[-1] > 0 and asteroid > 0:
                    S.append(asteroid)
                else:
                    while S and S[-1] > 0 and asteroid < 0 and S[-1] < abs(asteroid):
                        S.pop()
                    if S:
                        if S[-1] > 0 and asteroid < 0:
                            if S[-1] == abs(asteroid):
                                S.pop()
                        else:
                            S.append(asteroid)

                    else:
                        S.append(asteroid)
            else:
                S.append(asteroid)

        return S 