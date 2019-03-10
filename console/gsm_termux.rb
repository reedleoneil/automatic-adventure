require 'paho-mqtt'

client = PahoMqtt::Client.new()

client.on_message do |p|
	puts "Topic: #{p.topic}\nPayload: #{p.payload}\nQoS: #{p.qos}"

	number = p.payload[0..10]
	message = p.payload[11..p.payload.length]

	`termux-sms-send -n #{number} \"#{message}\"`
end

client.connect('192.168.1.100', 1883, client.keep_alive, true, true)
client.subscribe(["lailanie/gsm", 2])

loop do
	client.loop_read
	client.loop_write
end


