import java.sql.*;
import java.util.*;
class InsertResult{
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
rs.moveToInsertRow();
rs.updateString("Rollno","13");
rs.updateString("name","chaithra");
rs.updateString("branch","cse");
rs.updateString("address","hyderabad");
rs.updateString("Dreamcompany","Infosys");
rs.insertRow();
con.commit();
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
