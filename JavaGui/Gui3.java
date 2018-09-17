import javax.swing.*;
import java.awt.*;
import java.awt.event.*;



public class Gui3 extends JFrame implements KeyListener, ActionListener{

	static JFrame bframe;
	static JPanel p;
	static JLabel f1,f2;	//one says 'hello', the screams yellow


	public Gui3() {
		p = new JPanel(new GridLayout(3,2));  // THIS LAYOUT MANAGER WILL Try to arrange components into a 3x2 grid
		this.add(p);

		//component 1
		f1 = new JLabel("hello there, how is this working out for you so far?");
		p.add(f1);		//add it to the JPanel


		//component 2
		f2 = new JLabel("YELLOW!");
		f2.setForeground(Color.yellow);
		f2.setFont(new Font("Arial Rounded MT Bold", Font.PLAIN, 72));
		p.add(f2);

		//components 3,4,5,6
		JTextField f1 = new JTextField("enter something:");
		p.add(f1);
		f1.addKeyListener(this);

		p.add(new JTextField("and here - even though I am big, you can only type one line"));
		JTextArea txtArea = new JTextArea(6,8);
		p.add(txtArea);
		txtArea.addKeyListener(this);
		p.add(new JLabel(new ImageIcon("pic1.png")));	//can be a url as well

	}


	public void actionPerformed(ActionEvent e) {
	}


    public void keyTyped(KeyEvent e) {
        displayInfo(e, "KEY TYPED: ");
    }

    public void keyPressed(KeyEvent e) {
        displayInfo(e, "KEY PRESSED: ");
    }

    public void keyReleased(KeyEvent e) {
        displayInfo(e, "KEY RELEASED: ");
    }

    private void displayInfo(KeyEvent e, String keyStatus){
        
        //You should only rely on the key char if the event
        //is a key typed event.
	System.out.println(">>" + keyStatus);
        int id = e.getID();
        String keyString;
        if (id == KeyEvent.KEY_TYPED) {
            char c = e.getKeyChar();
            System.out.println("key character = '" + c + "'");
        } else {
            int keyCode = e.getKeyCode();
            System.out.println("key code = " + keyCode
                    + " (" + KeyEvent.getKeyText(keyCode) + ")");
        }
        
        int modifiersEx = e.getModifiersEx();
        String modString = "extended modifiers = " + modifiersEx;
        String tmpString = KeyEvent.getModifiersExText(modifiersEx);
        if (tmpString.length() > 0) {
            modString += " (" + tmpString + ")";
        } else {
            modString += " (no extended modifiers)";
        }
	System.out.println(modString);
        
        String actionString = "action key? ";
        if (e.isActionKey()) {
            actionString += "YES";
        } else {
            actionString += "NO";
        }
	System.out.println(actionString);
        
        String locationString = "key location: ";
        int location = e.getKeyLocation();
        if (location == KeyEvent.KEY_LOCATION_STANDARD) {
            locationString += "standard";
        } else if (location == KeyEvent.KEY_LOCATION_LEFT) {
            locationString += "left";
        } else if (location == KeyEvent.KEY_LOCATION_RIGHT) {
            locationString += "right";
        } else if (location == KeyEvent.KEY_LOCATION_NUMPAD) {
            locationString += "numpad";
        } else { // (location == KeyEvent.KEY_LOCATION_UNKNOWN)
            locationString += "unknown";
        }
	System.out.println(locationString + "\n");
    }
}

