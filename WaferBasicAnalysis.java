public class WaferBasicAnalysis {

    public static void main(String[] args) {

        // 6 x 6 wafer map
        int[][] wafer = {
            {0, 0, 1, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0},
            {0, 0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0, 0}
        };

        int defectiveDies = 0;
        int totalDies = 0;

        // Analyze wafer
        for (int i = 0; i < wafer.length; i++) {
            for (int j = 0; j < wafer[i].length; j++) {

                totalDies++;

                if (wafer[i][j] == 1) {
                    defectiveDies++;
                }
            }
        }

        double defectDensity =
                ((double) defectiveDies / totalDies) * 100;

        System.out.println("===== WAFER ANALYSIS =====");
        System.out.println("Total Dies       : " + totalDies);
        System.out.println("Defective Dies   : " + defectiveDies);
        System.out.printf("Defect Density   : %.2f%%\n", defectDensity);

        if (defectDensity > 10) {
            System.out.println("Wafer Status     : DEFECTIVE");
        } else {
            System.out.println("Wafer Status     : NORMAL");
        }
    }
}