public class FindGuitarTester {

    public static void main(String[] args) {
        Inventory inventory = new Inventory();
        Guitar erinLike = new Guitar("", 0, "Fender", "Startocastor", "electric", "Alder", "Alder");

        Guitar guitar = inventory.search(erinLike);
        if (guitar != null) {
            System.out.println("Guitar found: ");
            System.out.println("Serial Number: " + guitar.getSerialNumber());
            System.out.println("Price: $" + guitar.getPrice());
            System.out.println("Model: " + guitar.getModel());
            System.out.println("Type: " + guitar.getType());
            System.out.println("Back Wood: " + guitar.getBackWood());
            System.out.println("Top Wood: " + guitar.getTopWood());
        } else {
            System.out.println("Guitar not found.");
        }
    }
}
