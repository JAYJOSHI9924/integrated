
public class AIWaferAnalyzer extends WaferAnalyzer
        implements ReportGenerator, DataExporter {

    public AIWaferAnalyzer(String analyzerName) {
        super(analyzerName); // Calls parent constructor
    }

    @Override
    public void analyze(Wafer wafer, InspectionResult result) {

        System.out.println("\n----- AI WAFER ANALYSIS -----");

        super.analyze(wafer, result); // Calls parent method

        System.out.println("AI Analysis completed.");
        System.out.println(
            "Confidence: " + result.getConfidence() + "%"
        );
    }

    public void showAIAnalysis(InspectionResult result) {
        System.out.println("\n----- AI ANALYSIS -----");
        System.out.println("Defect Pattern : " + result.getDefectType());
        System.out.println("Confidence     : " + result.getConfidence() + "%");
    }

    @Override
    public void generateReport() {
        System.out.println("Wafer inspection report generated.");
    }

    @Override
    public void exportData() {
        System.out.println("Inspection data exported successfully.");
    }
}
