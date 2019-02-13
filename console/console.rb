require 'rubyserial'
require 'json'
require 'securerandom'
require 'paho-mqtt'

client = PahoMqtt::Client.new()
client.connect('localhost', 1883, client.keep_alive, true, true)

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
				uuid = SecureRandom.uuid
				`fswebcam -d /dev/video0 ~/public/#{uuid}.jpg`
				payload['image'] = "http://192.168.1.100:4567/#{uuid}.jpg"
				payload = payload.to_json
				client.publish("lailanie", payload, false, 1)
				client.loop_write
				puts payload
			end
		rescue

		end
	end
}

loop do
  
end
