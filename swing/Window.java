import javax.swing.*; 
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Container;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JTextField;


public class Window extends JPanel {  

	
	private static final long serialVersionUID = 1L;
	
	private JTextField t;
	private JButton b1, b2, b3,b4,b5,b6,b7,b8,b9;
	
	private JTextArea txtArea;
	private JTextField txtfield;
	
	private Client client;
	
	public Window(Client client) { 
		this.client = client;
		JFrame f = new JFrame();
	    f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    Container panel = f.getContentPane();
	    JPanel buttons = new JPanel();
		 
	    t = new JTextField(40);
		t.setPreferredSize(new Dimension(250, 150));
		panel.add(t, BorderLayout.CENTER);
		
		b1 = new JButton("Search");//creating instance of JButton  
		buttons.add(b1);
		
		b2 = new JButton("Play");
		buttons.add(b2);
		
		b3 = new JButton("Exit");
		buttons.add(b3);
		
		panel.add(buttons,BorderLayout.SOUTH);
		
		
		JToolBar toolbar = new JToolBar();
		b4 = new JButton("Search");//creating instance of JButton  
		b5 = new JButton("Play");
		b6 = new JButton("Exit");
		toolbar.add(b4);
		toolbar.add(b5);
		toolbar.add(b6);
		panel.add(toolbar,BorderLayout.NORTH);
		
		JMenuBar mb=new JMenuBar(); 
		b7 = new JButton("Search");//creating instance of JButton  
		b8 = new JButton("Play");
		b9 = new JButton("Exit");
		mb.add(b7);
		mb.add(b8);
		mb.add(b9);
		f.setJMenuBar(mb);
		
		
	    //pack() method calculates and assign appropriate size for frame
	    f.pack();
	 
	    //Making the frame visible
	    f.setVisible(true);	

	    txtfield = new JTextField("target media or group: ",30);
	    txtArea = new JTextArea(5,60);
	    
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
		if(e.getSource() == b1 || e.getSource() == b4||e.getSource() == b7) {
			System.out.println("Request to search...");
			String response = client.send("search " + txtfield.getText());
			if(response != null) {txtArea.append(response);}
			else {txtArea.append("Try another name...");}
		} else if (e.getSource() == b2||e.getSource() == b5||e.getSource() == b8) {
			System.out.println("Request to play...");			
			String response = client.send("play " + txtfield.getText());
			if(response != null) {txtArea.append(response);}
			else {txtArea.append("Try another name...");}
		} else if (e.getSource() == b3||e.getSource() == b6||e.getSource() == b9) {
			System.exit(0);
		};
	}

	}
	

} 