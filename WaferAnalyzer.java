
public class WaferAnalyzer extends Analyzer {

    protected String analyzerName;

    public WaferAnalyzer(String analyzerName) {
        this.analyzerName = analyzerName;
    }

    @Override
    public void analyze(Wafer wafer, InspectionResult result) {

        System.out.println("\n----- WAFER ANALYSIS -----");
        System.out.println("Analyzer : " + analyzerName);
        System.out.println("Wafer ID : " + wafer.getWaferId());
        System.out.println("Status   : " + result.getStatus());
        System.out.println("Defect   : " + result.getDefectType());
    }

    // Method overloading
    public void analyze(Wafer wafer) {
        System.out.println(
            "Basic analysis of wafer: " + wafer.getWaferId()
        );
    }
} 