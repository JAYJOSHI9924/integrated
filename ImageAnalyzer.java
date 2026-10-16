
public class ImageAnalyzer extends Analyzer {

    @Override
    public void analyze(Wafer wafer, InspectionResult result) {

        System.out.println("\n----- IMAGE ANALYSIS -----");

        System.out.println("Wafer ID   : " + wafer.getWaferId());
        System.out.println("Image Name : " + wafer.getImageName());

        System.out.println("Image analysis completed.");
        System.out.println("Detected pattern: " + result.getDefectType());
    }
}
