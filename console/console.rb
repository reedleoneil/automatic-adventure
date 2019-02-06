require 'rubyserial'

serialport = Serial.new '/dev/ttyACM0'

Thread.new {
	while true do
		x = ''
		payload = "{"
		while x != '{' do
			x = serialport.read 1
		end
		while x != '}' do
			x = serialport.read 1
			if x != '' then payload << x end
		end
		puts payload
		`fswebcam`
	end
}
while true do

end
