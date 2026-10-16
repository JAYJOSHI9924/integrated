
public abstract class Analyzer {

    // Abstract method
    public abstract void analyze(Wafer wafer, InspectionResult result);

    // Normal method
    public void showSystemMessage() {
        System.out.println("Semiconductor Wafer Inspection System");
    }
}
