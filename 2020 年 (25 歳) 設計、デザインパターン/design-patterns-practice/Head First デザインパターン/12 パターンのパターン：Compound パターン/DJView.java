import java.awt.*;
import java.awt.event.*;
import javax.swing.*;



// BeatModel の 2 つの側面を表示
public class DJView implements ActionListener, BeatObserver, BPMObserver
{
    BeatModelInterface model;
    ControllerInterface controller;

    JFrame viewFrame;
        JPanel viewPanel;
            JPanel bpmPanel;
                BeatBar beatBar;
                JLabel bpmOutputLabel;

    JFrame controlFrame;
        JMenuBar menuBar;
            JMenu menu;
                JMenuItem startMenuItem;
                JMenuItem stopMenuItem;
                JMenuItem exit;

        JPanel controlPanel;
            JPanel insideControlPanel;
                JPanel enterPanel;
                    JLabel bpmLabel;
                    JTextField bpmTextField;
                JButton setBPMButton;
                JPanel buttonPanel;
                    JButton increaseBPMButton;
                    JButton decreaseBPMButton;



    public DJView(ControllerInterface controller, BeatModelInterface model)
    {
        this.controller = controller;
        this.model = model;

        model.registerObserver((BeatObserver)this);
        model.registerObserver((BPMObserver)this);
    }

    // Model の View を含む interface
    public void createView()
    {
        // 生成   
        viewFrame = new JFrame("View");
            viewPanel = new JPanel(new GridLayout(1, 2));       // 1 行 2 列
                bpmPanel = new JPanel(new GridLayout(2, 1));    // 2 行 1 列
                    beatBar = new BeatBar();
                    bpmOutputLabel = new JLabel("offline", SwingConstants.CENTER);

        // 親子
        viewFrame.getContentPane().add(viewPanel, BorderLayout.CENTER);
            viewPanel.add(bpmPanel);
                bpmPanel.add(beatBar);
                bpmPanel.add(bpmOutputLabel);

        // 設定
        viewFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        viewFrame.setSize(new Dimension(100, 80));
        viewFrame.pack();
                    beatBar.setValue(0);
 
        // 表示
        viewFrame.setVisible(true);        
    }

    // UserControl 群を含むその他 interface
    public void createControls()
    {
        // 生成
        controlFrame = new JFrame("Control");
            menuBar = new JMenuBar();
                menu = new JMenu("DJ Control");
                    startMenuItem = new JMenuItem("Start");
                    stopMenuItem = new JMenuItem("Stop");
                    exit = new JMenuItem("Quit");

            controlPanel = new JPanel(new GridLayout(1, 2));
                insideControlPanel = new JPanel(new GridLayout(3, 1));
                    enterPanel = new JPanel(new GridLayout(1, 2));
                        bpmLabel = new JLabel("Enter BPM:", SwingConstants.RIGHT);
                        bpmTextField = new JTextField(2);
                    setBPMButton = new JButton("Set");
                    buttonPanel = new JPanel(new GridLayout(1, 2));
                        increaseBPMButton = new JButton(">>");
                        decreaseBPMButton = new JButton("<<");

        // 親子
        controlFrame.setJMenuBar(menuBar);
            menuBar.add(menu);
                menu.add(startMenuItem);
                menu.add(stopMenuItem); 
                menu.add(exit);

        controlFrame.getContentPane().add(controlPanel, BorderLayout.CENTER);
            controlPanel.add(insideControlPanel);
                insideControlPanel.add(enterPanel);
                    enterPanel.add(bpmLabel);
                    enterPanel.add(bpmTextField);
                insideControlPanel.add(setBPMButton);
                insideControlPanel.add(buttonPanel);
                    buttonPanel.add(decreaseBPMButton);
                    buttonPanel.add(increaseBPMButton);

        // 設定
        JFrame.setDefaultLookAndFeelDecorated(true);

        controlFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        controlFrame.setSize(new Dimension(100, 80));
        controlFrame.pack();
        controlFrame.getRootPane().setDefaultButton(setBPMButton);
                    startMenuItem.addActionListener((event) -> controller.start());
                    stopMenuItem.addActionListener((event) -> controller.stop());
                    exit.addActionListener((event) -> System.exit(0));

                        bpmLabel.setBorder(BorderFactory.createEmptyBorder(5,5,5,5));
                        bpmOutputLabel.setBorder(BorderFactory.createEmptyBorder(5,5,5,5));

                    setBPMButton.setSize(new Dimension(10,40));
                    setBPMButton.addActionListener(this);

                        increaseBPMButton.addActionListener(this);
                        decreaseBPMButton.addActionListener(this);

        // 表示
        controlFrame.setVisible(true);
    }

    public void enableStopMenuItem()
    {
        stopMenuItem.setEnabled(true);
	}

    public void disableStopMenuItem()
    {
        stopMenuItem.setEnabled(false);
    }

    public void enableStartMenuItem()
    {
        startMenuItem.setEnabled(true);
	}

    public void disableStartMenuItem()
    {
        startMenuItem.setEnabled(false);
	}



    @Override
    public void actionPerformed(ActionEvent event)
    {
        System.out.println("actionPerformed()");



        if (event.getSource() == setBPMButton)
        {
			int bpm = 90;

			String bpmText = bpmTextField.getText();

			if (bpmText == null || bpmText.contentEquals(""))
            {
				bpm = 90;
			}
            else
            {
				bpm = Integer.parseInt(bpmTextField.getText());
			}

        	controller.setBPM(bpm);
		}
        else if (event.getSource() == increaseBPMButton)
        {
			controller.increaseBPM();
		}
        else if (event.getSource() == decreaseBPMButton)
        {
			controller.decreaseBPM();
		}
    }



    @Override
    public void updateBeat()
    {
		System.out.println("updateBeat()");

        if (beatBar != null)
        {
			 beatBar.setValue(100);
		}
	}

    @Override
    public void updateBPM()
    {
        System.out.println("updateBPM()");

        int bpm = model.getBPM();

        if (bpm == 0)
        {
            if (bpmOutputLabel != null)
            {
                bpmOutputLabel.setText("offline");
            }
        }
        else
        {
            if (bpmOutputLabel != null)
            {
                bpmOutputLabel.setText("Current BPM: " + bpm);
            }
        }
    }
}
