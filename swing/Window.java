import javax.swing.*;
import javax.swing.GroupLayout.SequentialGroup;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Container;


public class Window extends JPanel {  

	
	private static final long serialVersionUID = 1L;
	
	private JTextField t;
	private JButton b1, b2, b3,b4,b5,b6,b7,b8,b9;
	
	private JTextArea txtArea;
	private JLabel jLabel1;
	
	private JTextField txtfield;
	
	private Client client;
	
	public Window(Client client) { 
		this.client = client;
		JFrame f = new JFrame();
	    f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    Container panel = f.getContentPane();
	    JPanel buttons = new JPanel();
		JPanel affiche = new JPanel();


	    t = new JTextField(40);
		t.setPreferredSize(new Dimension(250, 150));
		panel.add(t, BorderLayout.CENTER);
		
		b1 = new JButton("Search");//creating instance of JButton  
		buttons.add(b1);
		
		b2 = new JButton("Play");
		buttons.add(b2);
		
		b3 = new JButton("Exit");
		buttons.add(b3);
		
		// the buttom buttons
		panel.add(buttons,BorderLayout.SOUTH);
		
		
		JToolBar toolbar = new JToolBar();
		b4 = new JButton("Add photo");//creating instance of JButton  
		b5 = new JButton("Add video");
		b6 = new JButton("Help");
		toolbar.add(b4);
		toolbar.add(b5);
		toolbar.add(b6);
		// second line buttons
		panel.add(toolbar,BorderLayout.NORTH);
		
		JMenuBar mb=new JMenuBar(); 
		b7 = new JButton("Search");//creating instance of JButton  
		b8 = new JButton("Play");
		b9 = new JButton("Exit");
		mb.add(b7);
		mb.add(b8);
		mb.add(b9);
		// the upmost buttons
		f.setJMenuBar(mb);
		
		
	  
		jLabel1 = new JLabel();
		jLabel1.setText("Enter the name : ");
		affiche.add(jLabel1);
		
		




	    txtfield = new JTextField(30);
		affiche.add(txtfield);
	    
		txtArea = new JTextArea(5,60);
		txtArea.append("Two examples are provided for showcase : \nyou can enter name : 'video' or 'tool' and then press search or play");
		affiche.add(txtArea);
		
		panel.add(affiche);

  //pack() method calculates and assign appropriate size for frame
  f.pack();
	 
  //Making the frame visible
  f.setVisible(true);	

		b1.addActionListener(new Listener());
		b2.addActionListener(new Listener());
		b3.addActionListener(new Listener());
		b4.addActionListener(new Listener());
		b5.addActionListener(new Listener());
		b6.addActionListener(new Listener());
		b7.addActionListener(new Listener());
		b8.addActionListener(new Listener());
		b9.addActionListener(new Listener());
		
	};
	
 	//Implementation of listener using version 3.
	class Listener implements  ActionListener{
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == b4){
		   txtArea.setText("");
           String _name = JOptionPane.showInputDialog("enter photo name");
		   String _path = JOptionPane.showInputDialog("enter photo path");
		   String _hight = JOptionPane.showInputDialog("enter photo hight (must be double)");
		   String _width = JOptionPane.showInputDialog("enter photo width (must be double)");
		   System.out.println("Request to add photo...");
		   String response = client.send("add_photo " + _name+" "+_path + " "+_hight+" "+_width);
		   if(response != null) {txtArea.append("\n"+response);}
		   else {txtArea.append("\nFiled to add");}



		}

		else if (e.getSource() == b5){
			txtArea.setText("");
			String _name = JOptionPane.showInputDialog("enter photo name");
			String _path = JOptionPane.showInputDialog("enter photo path");
			String _duration = JOptionPane.showInputDialog("enter photo hight (must be integer)");
			System.out.println("Request to add video...");
			String response = client.send("add_video " + _name+" "+_path + " "+_duration);
 		    if(response != null) {txtArea.append("\n"+response);}
		    else {txtArea.append("\nFiled to add");}


		 }

		 else if (e.getSource() == b6){
			txtArea.setText("");
			txtArea.append("Two examples are provided for showcase : \nyou can enter name : 'video' or 'tool' and then press search or play\nYou can aswell try and add your own media using add photo and add video\nfor example you can add a new video by passing its name , path and its duration.");
		 }



		else if( e.getSource() == b1||e.getSource() == b7) {
			txtArea.setText("");
			System.out.println("Request to search...");
			String response = client.send("search " + txtfield.getText());
			if(response != null) {txtArea.append("\n"+response);}
			else {txtArea.append("\nTry another name...");}
		} else if (e.getSource() == b2||e.getSource() == b5||e.getSource() == b8) {
			txtArea.setText("");
			System.out.println("Request to play...");			
			String response = client.send("play " + txtfield.getText());
			if(response != null) {txtArea.append("\n"+response);}
			else {txtArea.append("\nTry another name...");}
		} else if (e.getSource() == b3||e.getSource() == b6||e.getSource() == b9) {
			txtArea.setText("");
			System.exit(0);
		};
	}

	}
	

} 