import { exec, execFile } from 'child_process';
import { SerialPort, ReadlineParser } from 'serialport';

const port = new SerialPort({ path: '/dev/ttyACM0', baudRate: 9600 });
const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }));

const currentValues = {
  percentage: 0,
};

port.on('open', () => {
  console.log('serial port open');
});

parser.on('data', async (data) => {
  data = data.replace(/'/g, '"');

  try {
    const parsedData = JSON.parse(data);
    const { percentage, activeButton } = parsedData;
    console.log(parsedData);

    if (activeButton === 2) {
      exec('wmctrl -a Google Chrome', (err, stdout, stderr) => {
        if (err) {
          execFile('sensible-browser');
          return;
        }
      });
    } else if (activeButton === 3) {
      exec('wmctrl -a Spotify', (err, stdout, stderr) => {
        if (err) {
          execFile('spotify');
          return;
        }
      });
    }

    if (percentage !== currentValues.percentage) {
      exec(
        `amixer -D pulse set Master ${percentage}%`,
        (err, stdout, stderr) => {}
      );
      currentValues.percentage = percentage;
    }
  } catch (error) {
    // console.log(error);
  }
});
