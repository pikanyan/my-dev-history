// View という Context に
// 賢さを与える Strategy
public interface ControllerInterface
{
	void start();
	void stop();
	void increaseBPM();
	void decreaseBPM();
 	void setBPM(int bpm);
}
