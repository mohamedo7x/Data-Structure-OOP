import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Inventory {
	private List<Guitar> guitars;
	public Inventory () {
		this.guitars = new ArrayList<>();
	}
	
	public void addGuitar  (String serialNumber,double price,String builder,String model,String type,String backWood,String topWood){
		Guitar guitar = new Guitar (serialNumber , price , builder , model , type, backWood , topWood); 
		guitars.add(guitar);
	}
	
	public Guitar getGuitar (String serialName) {  
		for(Guitar guitar : guitars) {
			if(guitar.getSerialNumber().equals(serialName)) {
				return guitar;
			}
		}
		return null;
	}
	public Guitar search(Guitar searchGuitar) {
        for (Guitar guitar : guitars) {
            String builder = searchGuitar.getBuilder();
            if (builder != null && !builder.equals("") && !builder.equals(guitar.getBuilder()))
                continue;
            String model = searchGuitar.getModel();
            if (model != null && !model.equals("") && !model.equals(guitar.getModel()))
                continue;
            String type = searchGuitar.getType();
            if (type != null && !type.equals("") && !type.equals(guitar.getType()))
                continue;
            String backWood = searchGuitar.getBackWood();
            if (backWood != null && !backWood.equals("") && !backWood.equals(guitar.getBackWood()))
                continue;
            String topWood = searchGuitar.getTopWood();
            if (topWood != null && !topWood.equals("") && !topWood.equals(guitar.getTopWood()))
                continue;
            return guitar; // found a match
        }
        return null; // no match found
    }
}
