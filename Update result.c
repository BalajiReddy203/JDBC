
import java.sql.*;
import java.util.*;
class UpdateResult{
public static void main(String args[]) throws Exception{
Connection con=null;
Statement stmt=null;
try{
Class.forName("oracle.jdbc.driver.OracleDriver");
con=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","system","aits");
con.setAutoCommit(false);
stmt=con.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE,ResultSet.CONCUR_UPDAT
ABLE);
String sQuery="Select Rollno,name,branch,address,Dreamcompany from 
aitscse2a";
ResultSet rs=stmt.executeQuery(sQuery);
int i=1;
rs.beforeFirst();
while(rs.next()){
if((rs.getString("branch")).equals("cse")){
String newName=rs.getString("name")+"r";
rs.updateString("name",newName);
rs.updateRow();
}
}
rs.beforeFirst();
System.out.println("roll\t name \t\t branch");
while(rs.next()){
System.out.println(rs.getString("Rollno")+"\t"+rs.getString("name")+"\t"+rs.getString("branc
h"));
}
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
