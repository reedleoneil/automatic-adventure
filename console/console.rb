require 'rubyserial'
require 'json'
require 'securerandom'

serialport = Serial.new '/dev/ttyUSB0'

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
		begin
			payload = JSON.parse(payload)
			if payload['isTrafficLightRed'] == 0 && payload['sensorReading'] == 0 then
			`fswebcam -d /dev/video0 ~/public/#{SecureRandom.uuid}.jpg`
			#Send mqtt
			puts payload
			end
		rescue

		end
	end
}
while true do

end
