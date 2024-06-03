import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
public class Test {
    public static void main(String[] args) throws IOException {
        File file = new File("/Users/christineswann/Documents/GitHub/PokemonBattleSim-V.0.0.1/text/Data1.txt");


        //Reading:
        String line2 = Files.readAllLines(Paths.get(file.getAbsolutePath())).get(2); /*Read specific lines */
        System.out.println(line2);


        //Writning:

        FileInputStream fis = new FileInputStream(file);
        InputStreamReader isr = new InputStreamReader(fis);
        BufferedReader br = new BufferedReader(isr);
        String line = br.readLine();
        FileWriter fr = new FileWriter(file, true);
        BufferedWriter bw = new BufferedWriter(fr);

        if ((line = br.readLine()) != null || br.readLine() != "") {
            bw.newLine();
        } /* Adding new lines */
        PrintWriter pr = new PrintWriter(bw);
        
        String line4 = Files.readAllLines(Paths.get(file.getAbsolutePath())).get(4);
        System.out.println(line4);
        int line4Length = (Files.readAllLines(Paths.get(file.getAbsolutePath())).get(4)).length();
        

        File inputFile = new File("/Users/christineswann/Documents/GitHub/PokemonBattleSim-V.0.0.1/text/Data1.txt");
        File tempFile = new File("/Users/christineswann/Documents/GitHub/PokemonBattleSim-V.0.0.1/text/myTempFile.txt");
        
        BufferedReader reader = new BufferedReader(new FileReader(inputFile));
        BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile));

        String currentLine = "hello";
        String lineToRemove;
        while ((currentLine = reader.readLine()) != null) {
            String trimmedLine = currentLine.trim();
            lineToRemove = "hello";
            if (trimmedLine.equals(lineToRemove)) continue;
            writer.write(currentLine + System.getProperty("line.separator"));
        }
        writer.close(); 
        reader.close(); 
        boolean successful = tempFile.renameTo(inputFile);

        pr.write("newthings");




        fis.close();
        isr.close();
        pr.close();
        bw.close();
        br.close();


    }
}
