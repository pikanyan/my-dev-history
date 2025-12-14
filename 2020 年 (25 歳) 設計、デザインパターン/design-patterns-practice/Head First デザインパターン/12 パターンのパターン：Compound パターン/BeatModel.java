import java.io.*;
import java.util.List;
import java.util.ArrayList;

import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.Line;



public class BeatModel implements BeatModelInterface, Runnable
{
    List<BeatObserver> beatObservers = new ArrayList<BeatObserver>();
	List<BPMObserver> bpmObservers = new ArrayList<BPMObserver>();

	int bpm = 90;
    
    Thread thread;
	boolean stop = false;

    Clip clip;



    @Override
    public void initialize()
    {
        try
        {
			File resource = new File("clap.wav");

			clip = (Clip) AudioSystem.getLine(new Line.Info(Clip.class));
			clip.open(AudioSystem.getAudioInputStream(resource));
		}
		catch(Exception ex)
        {
			System.out.println("Error: Can't load clip");
			System.out.println(ex);
		}
    }

    @Override
    public void on()
    {
        System.out.println("on()");

        bpm = 90;
		notifyBPMObservers();
		thread = new Thread(this);
		stop = false;
		thread.start();
    }

    @Override
    public void off()
    {
        System.out.println("off()");
        
        stopBeat();
		stop = true;
    }

    @Override
    public void setBPM(int bpm)
    {
        this.bpm = bpm;

		notifyBPMObservers();
    }

    @Override
    public int getBPM()
    {
        return bpm;
    }

    @Override
    public void registerObserver(BeatObserver o)
    {
        beatObservers.add(o);
    }

    public void notifyBeatObservers()
    {
		for(int i = 0; i < beatObservers.size(); i++)
        {
			BeatObserver observer = (BeatObserver)beatObservers.get(i);
			observer.updateBeat();
		}
	}

    @Override
	public void removeObserver(BeatObserver o)
    {
        int i = beatObservers.indexOf(o);

		if (i >= 0)
        {
			beatObservers.remove(i);
		}
    }

    @Override
	public void registerObserver(BPMObserver o)
    {
        bpmObservers.add(o);
    }

    public void notifyBPMObservers()
    {
		for(int i = 0; i < bpmObservers.size(); i++)
        {
			BPMObserver observer = (BPMObserver)bpmObservers.get(i);

			observer.updateBPM();
		}
	}

    @Override
	public void removeObserver(BPMObserver o)
    {
        int i = bpmObservers.indexOf(o);

		if (i >= 0)
        {
			bpmObservers.remove(i);
		}
    }



    @Override
    public void run()
    {
        System.out.println("run()");

        while (!stop)
        {
			playBeat();
			notifyBeatObservers();

			try
            {
				Thread.sleep(60000/getBPM());
			}
            catch (Exception e)
            {

            }
		}
    }



    public void playBeat()
    {
		clip.setFramePosition(0);
		clip.start();
	}

	public void stopBeat()
    {
		clip.setFramePosition(0);
		clip.stop();
	}
}
