
public class Defect {

    private String type;
    private double confidence;

    // Constructor
    public Defect(String type, double confidence) {
        this.type = type;
        this.confidence = confidence;
    }

    // Getter for defect type
    public String getType() {
        return type;
    }

    // Getter for confidence
    public double getConfidence() {
        return confidence;
    }

    // Display defect information
    public void displayDefect() {

        System.out.println("Defect Type : " + type);
        System.out.println("Confidence  : " + confidence + "%");
    }
}
