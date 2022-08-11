import java.sql.*;
import java.util.*;
class DeleteResult{
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
rs.first();//ResultSet object points first row of the table
rs.deleteRow();//Deletes the table row of the ResultSet object pointing
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
