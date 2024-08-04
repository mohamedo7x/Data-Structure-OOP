
public class Guitar {
	private String serialNumber;
	private double price;
	private	String builder;
	private String model;
	private String type;
	private	String backWood;
	private String topWood;
	
	public String getSerialNumber () {
		return this.serialNumber;
	}
	public double getPrice () {
		return this.price;
	}
	public void setPrice (double price) {
		this.price = price;
	}
	public String getBuilder () {
		return this.builder;
	}
	public String getModel () {
		return this.model;
	}
	public String getType () {
		return this.type;
	}
	public String getBackWood () {
		return this.backWood;
	}
	public String getTopWood () {
		return this.topWood;
	}
	public Guitar(String serialNumber,double price,String builder,String model,String type,String backWood,String topWood){
		this.serialNumber = serialNumber;
		this.price = price;
		this.builder = builder;
		this.model = model;
		this.type = type;
		this.backWood = backWood;
		this.topWood = topWood;
	}
}
