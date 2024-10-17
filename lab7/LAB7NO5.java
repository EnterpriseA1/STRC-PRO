/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab7;

/**
 *
 * @author Kkhamwiset
 */
class Address {
    private String street;
    private String city;

    public Address(String street, String city) {
        this.street = street;
        this.city = city;
    }
    public String getStreet() {
        return street;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getAddressInfo() {
        return "Street: " + street + ", City: " + city;
    }
}

class Employee {
    private int id;
    private String name;
    private double salary;
    private Address address;

    public Employee(int id, String name, double salary, Address address) {
        this.id = id;
        this.name = name;
        this.salary = salary;
        this.address = address;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public Address getAddress() {
        return address;
    }

    public void setAddress(Address address) {
        this.address = address;
    }
    public String getDetails() {
        return "ID: " + id + ", Name: " + name + ", Salary: " + salary + 
               ", Address: " + address.getAddressInfo();
    }
}

class Manager extends Employee {
    private String parkingNo;

    // Constructor
    public Manager(int id, String name, double salary, Address address, String parkingNo) {
        super(id, name, salary, address);
        this.parkingNo = parkingNo;
    }

    public String getParkingNo() {
        return parkingNo;
    }

    public void setParkingNo(String parkingNo) {
        this.parkingNo = parkingNo;
    }
    @Override
    public String getDetails() {
        return super.getDetails() + ", Parking No: " + parkingNo;
    }
}

public class LAB7NO5{
    public static void main(String[] args) {
        Address address = new Address("123 NIG St", "Bangkok");
        Employee emp = new Manager(101, "John Doe", 50000, address, "A1");
        System.out.println(emp.getDetails());
    }
}
