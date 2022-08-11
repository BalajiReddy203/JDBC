class BatchUpdate{
public static void main(String args[]) throws Exception{
Connection con=null;
Statement stmt=null;
try{
Class.forName("oracle.jdbc.driver.OracleDriver");
con=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","system","aits");
con.setAutoCommit(false);
stmt=con.createStatement();
String q1="insert into aitscse2a values(507,'priya','cse','kadiri','google')";
stmt.addBatch(q1);
String q2="insert into aitscse2a 
values(508,'navya','cse','rayachoti','microsoft')";
stmt.addBatch(q2);
String q3="update aitscse2a set address='hyderabad' where Rollno='501'";
stmt.addBatch(q3);
stmt.executeBatch();
con.commit();
System.out.println("batchupdated successfully");
}
catch(ClassNotFoundException |SQLException e){
e.printStackTrace();
}
finally{
stmt.close();
con.close();
}
}
}
