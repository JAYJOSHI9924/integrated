
public class InspectionResult {

    private Defect defect;
    private String status;

    // Constructor
    public InspectionResult(Defect defect, String status) {
        this.defect = defect;
        this.status = status;
    }

    // Getter for defect
    public Defect getDefect() {
        return defect;
    }

    // Getter for status
    public String getStatus() {
        return status;
    }

    // Get defect type
    public String getDefectType() {
        return defect.getType();
    }

    // Get confidence
    public double getConfidence() {
        return defect.getConfidence();
    }

    // Display inspection result
    public void displayResult() {

        System.out.println("\n----- AI INSPECTION RESULT -----");

        defect.displayDefect();

        System.out.println("Status      : " + status);
    }
}
