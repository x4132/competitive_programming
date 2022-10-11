public class LC849MaximizeDistancetoClosestPerson {
    public int maxDistToClosest(int[] seats) {
        int maxDist = 0;
        boolean start = true;
        int curDist = 0;
         for (int i = 0; i < seats.length - 1; i++) {
            if (seats[i] == 1) {
                if (start == true) {
                    maxDist = curDist;
                    start = false;
                } else {
                    maxDist = Math.max(curDist / 2, maxDist);
                }

                curDist = 0;
            }
            curDist++;
        }

        if (seats[seats.length - 1] == 1) {
            if (start == true) {
                maxDist = curDist;
            } else {
                maxDist = Math.max(curDist / 2, maxDist);
            }
        } else {
            maxDist = Math.max(curDist, maxDist);
        }

        return maxDist;
    }
}